using CarWorkShop.Data.Interface;
using CarWorkShop.Data.Interfaces;
using CarWorkShop.Models;
using CarWorkShop.ViewModels;
using Microsoft.AspNetCore.Mvc;

namespace CarWorkShop.Controllers
{
    public class DashboardController : Controller
    {
        private readonly IDashboardRepository _dashboardRepository;
        private readonly IHttpContextAccessor _httpContextAccessor;
        private readonly ITicketRepository _ticketRepository;

        public DashboardController(IDashboardRepository dashboardRepository, IHttpContextAccessor httpContextAccessor, ITicketRepository ticketRepository)
        {
            _dashboardRepository = dashboardRepository;
            _httpContextAccessor = httpContextAccessor;
            _ticketRepository = ticketRepository;
        }
        public async Task<IActionResult> Index()
        {
            var userTickets = await _dashboardRepository.GetAllUserTickets();
            var dashboardViewModel = new DashboardViewModel()
            {
                Tickets = userTickets
            };
            return View(dashboardViewModel);
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
            };

            _ticketRepository.Update(ticket);

            return RedirectToAction("Index");
        }
        public async Task<IActionResult> EditUserCalender()
        {
            var acceptedTickets = await _dashboardRepository.GetUserAcceptedTickets();
            var dashboardViewModel = new CalenderViewModel()
            {
                AcceptedTickets = acceptedTickets
            };
            return View(dashboardViewModel);
        }
        public async Task<IActionResult> Finish(int id)
        {
            //Get selected ticket
            var ticket = await _ticketRepository.GetByIdAsync(id);

            if (ticket == null) return View("Error");
            //var acceptCalenderVM = new AcceptCalenderViewModel();
            return View(ticket);
        }
        [HttpPost, ActionName("Finish")]
        public async Task<IActionResult> FinishTicket(int id)
        {
            var ticket = await _ticketRepository.GetByIdAsyncNoTracking(id);
            if (ticket == null)
            {
                return View("Error");
            }
            //Update ticket assigned employee and change ticket status
            ticket.StateCategory = CarWorkShop.Data.Enum.StateCategory.Done; 
            _ticketRepository.Update(ticket);
            return RedirectToAction("Index");
        }
    }
}
