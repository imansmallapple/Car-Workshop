using Microsoft.AspNetCore.Identity;
using System.ComponentModel.DataAnnotations.Schema;

namespace CarWorkShop.Models
{
    public class User : IdentityUser
    {
        public string? Price { get; set; }
        public ICollection<Ticket>? Tickets { get; set; }
        public string Name {  get; set; }
        [ForeignKey("Calender")]
        public int? CalenderId { get; set; }
        public Calender ? Calender {  get; set; }
    }
}
