using CarWorkShop.Data.Enum;
using CarWorkShop.Models;

namespace CarWorkShop.ViewModels
{
    public class AcceptCalenderViewModel
    {
        //User part
        public int Id { get; set; }
        //public string UserId { get; set; }
        //public string UserName { get; set; }
        public WeekCategory? WeekCategory { get; set; }
        public FromWhenCategory? FromWhenCategory { get; set; }
        public TillWhenCategory? TillWhenCategory { get; set; }
        public StateCategory StateCategory { get; set; }
        public int CalenderId { get; set; }
        public int TicketId { get; set; }
        public Calender? Calender { get; set; }
    }
}
