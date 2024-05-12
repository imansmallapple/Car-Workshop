using CarWorkShop.Data.Enum;
using CarWorkShop.Models;

namespace CarWorkShop.ViewModels
{
    public class EditTicketViewModel
    {
        public int Id { get; set; }
        public string Brand { get; set; }
        public string Model { get; set; }
        public string RegistrationId { get; set; }
        public string Description { get; set; }
        public StateCategory StateCategory { get; set; }
        public int RepairEstimateId {  get; set; }
        public RepairEstimate? RepairEstimate { get; set; }
        public float? ClientPaid { get; set; }
    }
}
