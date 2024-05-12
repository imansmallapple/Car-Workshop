using CarWorkShop.Data;
using CarWorkShop.Data.Interfaces;
using CarWorkShop.Models;
using Microsoft.EntityFrameworkCore;

namespace CarWorkShop.Repository
{
    public class CalenderRepository : ICalenderRepository
    {
        private readonly ApplicationDbContext _context;
        private readonly IHttpContextAccessor _httpContextAccessor;

        public CalenderRepository(ApplicationDbContext context, IHttpContextAccessor httpContextAccessor)
        {
            _context = context;
            _httpContextAccessor = httpContextAccessor;
        }
        public bool Add(Calender calender)
        {
            throw new NotImplementedException();
        }

        public bool Delete(Calender calender)
        {
            throw new NotImplementedException();
        }

        public async Task<Calender> GetTicketCalender(int ticketId)
        {
            var ticketCalender = _context.Calenders.Where(c => c.TicketId == ticketId);
            return await ticketCalender.FirstOrDefaultAsync();
        }
        public bool Save()
        {
            throw new NotImplementedException();
        }

        public bool Update(Calender calender)
        {
            throw new NotImplementedException();
        }
    }
}
