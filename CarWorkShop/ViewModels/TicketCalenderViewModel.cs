using CarWorkShop.Data.Enum;
using CarWorkShop.Models;
using System.ComponentModel.DataAnnotations;

namespace CarWorkShop.ViewModels
{
    public class TicketCalenderViewModel
    {
        public WeekCategory? WeekCategory { get; set; }
        public FromWhenCategory? FromWhenCategory { get; set; }
        public TillWhenCategory? TillWhenCategory { get; set; }
    }
}
