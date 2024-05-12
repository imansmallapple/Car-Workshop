using CarWorkShop.Data.Enum;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
namespace CarWorkShop.Models
{
    public class Ticket
    {
        [Key]
        public int Id { get; set; }
        public string Brand { get; set; }
        public string Model { get; set; }
        public string RegistrationId {  get; set; }
        public string Description { get; set; }
        public string? EmployeeAssigned { get; set; }
        public StateCategory StateCategory { get; set; }
        //+= Amount * UnitPrice
        public float? TotalPrice { get; set; }
        public List<string>? TimeSlots { get; set; }
        public float? ClientPaid { get; set; }
        public bool? AcceptedOrNot { get; set; }
        [ForeignKey("User")]
        public string? UserId { get; set; }
        public User? User { get; set; }
        [ForeignKey("RepairEstimate")]
        public int RepairEstimateId { get; set; }
        public RepairEstimate? RepairEstimate { get; set; }
        [ForeignKey("Part")]
        public int? PartId { get; set; }
        public List<Part>? Parts { get; set; }
    }
}
