using CarWorkShop.Models;

namespace CarWorkShop.Data.Interfaces
{
    public interface ICalenderRepository
    {
        Task<Calender> GetTicketCalender(int ticketId);
        bool Add(Calender calender);
        bool Update(Calender calender);
        bool Delete(Calender calender);
        bool Save();
    }
}
