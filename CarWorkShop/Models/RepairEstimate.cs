using CarWorkShop.Data.Enum;
using System.ComponentModel.DataAnnotations;

namespace CarWorkShop.Models
{
    public class RepairEstimate
    {
        [Key]
        public int Id { get; set; }
        public string? Description {  get; set; }
        public float? cost { get; set; }
        public AttitudeCategory AttitudeCategory { get; set; }
    }
}
