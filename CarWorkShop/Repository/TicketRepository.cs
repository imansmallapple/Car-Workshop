using CarWorkShop.Data;
using CarWorkShop.Data.Interfaces;
using CarWorkShop.Models;
using Microsoft.EntityFrameworkCore;


namespace CarWorkShop.Repository
{
    public class TicketRepository : ITicketRepository
    {
        private readonly ApplicationDbContext _context;

        public TicketRepository(ApplicationDbContext context) 
        {
            _context = context;
        }
        public bool Add(Ticket ticket)
        {
            _context.Add(ticket);
            return Save();
        }

        public bool Delete(Ticket ticket)
        {
            _context.Remove(ticket);
            return Save();
        }

        public async Task<IEnumerable<Ticket>> GetAll()
        {
            return await _context.Tickets.ToListAsync();
        }

        public async Task<Ticket> GetByIdAsync(int id)
        {
            return await _context.Tickets.Include(i=>i.RepairEstimate).FirstOrDefaultAsync(t => t.Id == id);
        }

        public async Task<Ticket> GetByIdAsyncNoTracking(int id)
        {
            return await _context.Tickets.Include(i => i.RepairEstimate).AsNoTracking().FirstOrDefaultAsync(t => t.Id == id);
        }

        public async Task<IEnumerable<Ticket>> GetTicketByEmployee(string employee)
        {
            return await _context.Tickets.Where(c => c.EmployeeAssigned == employee).ToListAsync();
        }
        public bool Save()
        {
            var saved = _context.SaveChanges();
            return saved > 0 ? true : false;
        }

        public bool Update(Ticket ticket)
        {
            _context.Update(ticket);
            return Save();
        }
    }
}
