using System.ComponentModel.DataAnnotations;

namespace CarWorkShop.ViewModels
{
	public class CreatePartViewModel
	{
		public int Id { get; set; }
		[Display(Name = "Item Name")]
		[Required(ErrorMessage = "Part name is required")]
		public string Name { get; set; }
		[Display(Name = "Amount")]
		[Required(ErrorMessage = "Amount is required")]
		public float Amount { get; set; }
		[Display(Name = "UnitPrice")]
		[Required(ErrorMessage = "UnitPrice is required")]
		public float UnitPrice { get; set; }
		public int TicketId { get; set; }
	}
}
