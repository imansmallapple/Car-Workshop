using CarWorkShop.Data.Enum;
using CarWorkShop.Models;

namespace CarWorkShop.ViewModels
{
    public class CreateTicketViewModel
    {
        public int Id { get; set; }
        public string Brand { get; set; }
        public string Model { get; set; }
        public string RegistrationId { get; set; }
        public string Description { get; set; }
        public StateCategory StateCategory { get; set; }
        public string UserId { get; set; }
        public RepairEstimate? RepairEstimate { get; set; }
        //public List<Part>? Parts { get; set; }
        public float? ClientPaid { get; set; }
        public int? PartId { get; set; }
    }
}
