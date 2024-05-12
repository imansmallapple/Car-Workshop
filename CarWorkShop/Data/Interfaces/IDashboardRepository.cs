using CarWorkShop.Models;

namespace CarWorkShop.Data.Interface
{
    public interface IDashboardRepository
    {
        Task<List<Ticket>> GetAllUserTickets();
        Task<List<Ticket>> GetUserAcceptedTickets();
        Task<User> GetUserById(string id);
        Task<User> GetUserByIdNoTracking(string id);
        bool Update(User user);
        bool Save();
    }
}
