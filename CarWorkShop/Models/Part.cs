using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace CarWorkShop.Models
{
    public class Part
    {
        [Key]
		[DatabaseGenerated(DatabaseGeneratedOption.Identity)]
		public int Id { get; set; }
        public string Name { get; set; }
        public float Amount { get; set; }
        public float UnitPrice { get; set; }
        public int TicketId { get; set; }
    }
}
