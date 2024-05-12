using CarWorkShop.Data;
using CarWorkShop.Data.Interface;
using CarWorkShop.Models;
using Microsoft.EntityFrameworkCore;

namespace CarWorkShop.ViewModels
{
    public class DashboardRepository : IDashboardRepository
    {
        private readonly ApplicationDbContext _context;
        private readonly IHttpContextAccessor _httpContextAccessor;

        public DashboardRepository(ApplicationDbContext context, IHttpContextAccessor httpContextAccessor)
        {
            _context = context;
            _httpContextAccessor = httpContextAccessor;
        }
        public List<Ticket> Tickets { get; set; }

        public async Task<List<Ticket>> GetAllUserTickets()
        {
            var curUser = _httpContextAccessor.HttpContext?.User;
            var userTickets = _context.Tickets.Where(t => t.User.Id == curUser.GetUserId());
            return userTickets.ToList();
        }
        public async Task<List<Ticket>> GetUserAcceptedTickets()
        {
            //Current user all ticket
            var curUser = _httpContextAccessor.HttpContext?.User;
            var userAcceptedTickets = _context.Tickets.Where(t => t.EmployeeAssigned == curUser.GetUserName()).Where(t => t.AcceptedOrNot == true);
            //var userAcceptedTickets = _context.Tickets.Where(t => t.User.Id == curUser.GetUserId()).Where(t=>t.AcceptedOrNot == true);
            return userAcceptedTickets.ToList();
        }

        public async Task<User> GetUserById(string id)
        {
            return await _context.Users.FindAsync(id);
        }
        public async Task<User> GetUserByIdNoTracking(string id)
        {
            return await _context.Users.Where(u=>u.Id == id).AsNoTracking().FirstOrDefaultAsync();   
        }
        public bool Update(User user)
        {
            _context.Users.Update(user);
            return Save();
        }
        public bool Save()
        {
            var saved = _context.SaveChanges();
            return saved > 0 ? true : false;   
        }
    }
}
