using CarWorkShop.Data;
using CarWorkShop.Data.Interface;
using CarWorkShop.Data.Interfaces;
using CarWorkShop.Models;
using CarWorkShop.ViewModels;
using Microsoft.AspNetCore.Mvc;

namespace CarWorkShop.Controllers
{
    public class TicketController : Controller
    {
        //private readonly ApplicationDbContext _context;
        private readonly ITicketRepository _ticketRepository;
        private readonly IHttpContextAccessor _httpContextAccessor;
        private readonly IUserRepository _userRepository;
        private readonly IPartRepository _partRepository;
        private readonly ICalenderRepository _calenderRepository;

        public TicketController(ITicketRepository ticketRepository, IHttpContextAccessor httpContextAccessor, IUserRepository userRepository, IPartRepository partRepository, ICalenderRepository calenderRepository)
        {
            //_context = context;
            _ticketRepository = ticketRepository;
            _httpContextAccessor = httpContextAccessor;
            _userRepository = userRepository;
            _partRepository = partRepository;
            _calenderRepository = calenderRepository;
            //_calenderRepository = calenderRepository;
        }
        public async Task<IActionResult> Index()
        {
            //List<Ticket> tickets = _context.Tickets.ToList();
            IEnumerable<Ticket> tickets = await _ticketRepository.GetAll();
            return View(tickets);
        }
        public async Task<IActionResult> Detail(int id)
        {
            //we scan the club table and get the first/default one
            //when we do a join, we need use include(it is expensive)
            Ticket ticket = await _ticketRepository.GetByIdAsync(id);
            return View(ticket);
        }
        public IActionResult Create()
        {
            var curUserId = _httpContextAccessor.HttpContext.User.GetUserId();
            var createTicketViewModel = new CreateTicketViewModel { UserId = curUserId };
            return View(createTicketViewModel);
        }
        [HttpPost]
        public IActionResult Create(CreateTicketViewModel ticketVM)
        {
            if ((ModelState.IsValid))
            {
                //Create list of parts
               
                var ticket = new Ticket
                {
                    Brand = ticketVM.Brand,
                    Model = ticketVM.Model,
                    RegistrationId = ticketVM.RegistrationId,
                    Description = ticketVM.Description,
                    UserId = ticketVM.UserId,
                    RepairEstimate = new RepairEstimate
                    {
                        Description = ticketVM.RepairEstimate.Description,
                        cost = ticketVM.RepairEstimate.cost,
                        AttitudeCategory = ticketVM.RepairEstimate.AttitudeCategory,
                    },
                    ClientPaid = ticketVM.ClientPaid,
                    PartId = ticketVM.PartId,
                };
                _ticketRepository.Add(ticket);
                return RedirectToAction("Index");
            }
            return View(ticketVM);
        }
        public async Task<IActionResult> Edit(int id)
        {
            var ticket = await _ticketRepository.GetByIdAsync(id);
            if (ticket == null) return View("Error");
            var ticketVM = new EditTicketViewModel
            {
                Brand = ticket.Brand,
                Model = ticket.Model,
                RegistrationId = ticket.RegistrationId,
                Description = ticket.Description,
                StateCategory = ticket.StateCategory,
                RepairEstimateId = ticket.RepairEstimateId,
                ClientPaid = ticket.ClientPaid,
            };
            return View(ticketVM);
        }
        [HttpPost]
        public async Task<IActionResult> Edit(int id, EditTicketViewModel ticketVM)
        {
            if (!ModelState.IsValid)
            {
                ModelState.AddModelError("", "Failed to edit ticket");
                return View("Edit", ticketVM);
            }

            var userTicket = await _ticketRepository.GetByIdAsyncNoTracking(id);
            if (userTicket == null)
            {
                return View("Error");
            }

            var ticket = new Ticket
            {
                Id = id,
                Brand = ticketVM.Brand,
                Model = ticketVM.Model,
                RegistrationId = ticketVM.RegistrationId,
                Description = ticketVM.Description,
                RepairEstimateId = ticketVM.RepairEstimateId,
                RepairEstimate = ticketVM.RepairEstimate,
                ClientPaid = ticketVM.ClientPaid,
            };

            _ticketRepository.Update(ticket);

            return RedirectToAction("Index");
        }
        public async Task<IActionResult> Delete(int id)
        {
            var ticketDetails = await _ticketRepository.GetByIdAsync(id);
            if (ticketDetails == null) return View("Error");
            return View(ticketDetails);
        }
        [HttpPost, ActionName("Delete")]
        public async Task<IActionResult> DeleteTicket(int id)
        {
            var ticketDetails = await _ticketRepository.GetByIdAsync(id);
            if (ticketDetails == null) return View("Error");
            _ticketRepository.Delete(ticketDetails);
            return RedirectToAction("Index");
        }
        [HttpGet]
        public async Task<IActionResult> Accept(int id)
        {
            //We modify ticket state: Created->Processing, And add user's Calender information
            //Get current user
            var curUserId = _httpContextAccessor.HttpContext.User.GetUserId();
            User user = await _userRepository.GetUserByIdAsync(curUserId);
            //Get selected ticket
            var ticket = await _ticketRepository.GetByIdAsync(id);
            
            if (ticket == null) return View("Error");
            var acceptCalenderVM = new AcceptCalenderViewModel() {TicketId = ticket.Id };
            return View(acceptCalenderVM);
        }
        [HttpPost]
        public async Task<IActionResult> Accept(int id, AcceptCalenderViewModel acceptCalenderViewModel)
        {
            if (!ModelState.IsValid)
            {
                ModelState.AddModelError("", "Failed to accept ticket");
                return View("Accept", acceptCalenderViewModel);
            }
            //User operation
            var curUserId = _httpContextAccessor.HttpContext.User.GetUserId();
            User user = await _userRepository.GetUserByIdAsync(curUserId);         
            //Add new calender to user
            user.CalenderId = acceptCalenderViewModel.CalenderId;
            var Calender = new Calender
            {
                WeekCategory = acceptCalenderViewModel.WeekCategory,
                FromWhenCategory = acceptCalenderViewModel.FromWhenCategory,
                TillWhenCategory = acceptCalenderViewModel.TillWhenCategory,
                Id = (int)user.CalenderId,
                TicketId = acceptCalenderViewModel.TicketId,
            };
            user.Calender = Calender;
            _userRepository.Update(user);

            //Ticket operation
            var ticket = await _ticketRepository.GetByIdAsyncNoTracking(id);
            if (ticket == null)
            {
                return View("Error");
            }
            //Update ticket assigned employee and change ticket status
            ticket.StateCategory = CarWorkShop.Data.Enum.StateCategory.Processing;
            ticket.EmployeeAssigned = user.Name;
            ticket.AcceptedOrNot = true;
            _ticketRepository.Update(ticket);

            return RedirectToAction("Index");
        }
        [HttpGet]
        public async Task<IActionResult> Close(int id)
        {
            var ticket = await _ticketRepository.GetByIdAsync(id);
            if (ticket == null) return View("Error");
            //ticket.StateCategory = CarWorkShop.Data.Enum.StateCategory.Closed;
            //_ticketRepository.Update(ticket);
            return View();
        }
        [HttpPost, ActionName("Close")]
        public async Task<IActionResult> CloseTicket(int id)
        {
            var ticket = await _ticketRepository.GetByIdAsyncNoTracking(id);
            if (ticket == null)
            {
                return View("Error");
            }
            //Update ticket assigned employee and change ticket status
            ticket.StateCategory = CarWorkShop.Data.Enum.StateCategory.Closed;
            _ticketRepository.Update(ticket);
            return RedirectToAction("Index");
        }
        public async Task<IActionResult> AddParts(int id)
        {
            var ticket = await _ticketRepository.GetByIdAsync(id);
            var partVM = new CreatePartViewModel { TicketId = ticket.Id };
            return View(partVM);
	    }
        [HttpPost, ActionName("AddParts")]
        public async Task<IActionResult> PostParts(CreatePartViewModel partVM)
        {
			if ((ModelState.IsValid))
			{
				//Create list of parts

				var part = new Part
				{
					Name = partVM.Name,
                    Amount = partVM.Amount,
                    UnitPrice = partVM.UnitPrice,
                    TicketId = partVM.TicketId,
				};
				_partRepository.Add(part);
				return RedirectToAction("Index");
			}
			return View(partVM);
		}
        public async Task<IActionResult> PartsDetail(int id)
        {
            var ticketParts = await _partRepository.GetTicketAllParts(id);
            var ticketPrice = ticketParts.Sum(p=>p.Amount * p.UnitPrice);
            var PartDetailViewModel = new PartDetailViewModel()
            {
                Parts = ticketParts,
                TicketPrice = ticketPrice
            };
            return View(PartDetailViewModel);
        }
        public async Task<IActionResult> CalenderDetail(int id)
        {
            var ticketCalender = await _calenderRepository.GetTicketCalender(id);
            var TicketCalenderViewModel = new TicketCalenderViewModel()
            {
                WeekCategory = ticketCalender.WeekCategory,
                FromWhenCategory = ticketCalender.FromWhenCategory,
                TillWhenCategory = ticketCalender.TillWhenCategory,
            };
            return View(TicketCalenderViewModel);
        }
    }
}