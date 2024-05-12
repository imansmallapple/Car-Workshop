using CarWorkShop.Models;

namespace CarWorkShop.Data.Interfaces
{
    public interface ITicketRepository
    {
        Task<IEnumerable<Ticket>> GetAll();
        Task<Ticket> GetByIdAsync(int id);
        Task<Ticket> GetByIdAsyncNoTracking(int id);
        Task<IEnumerable<Ticket>> GetTicketByEmployee(string employee);
        bool Add(Ticket ticket);
        bool Update(Ticket ticket);
        bool Delete(Ticket ticket);
        bool Save();
    }
}
