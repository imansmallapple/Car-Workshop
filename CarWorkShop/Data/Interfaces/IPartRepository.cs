using CarWorkShop.Models;

namespace CarWorkShop.Data.Interfaces
{
    public interface IPartRepository
    {
        Task<List<Part>> GetTicketAllParts(int ticketId);
        bool Add(Part part);
        bool Update(Part part);
        bool Delete(Part part);
        bool Save();
    }
}
