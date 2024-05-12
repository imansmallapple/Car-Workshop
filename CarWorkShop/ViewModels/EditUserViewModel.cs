using CarWorkShop.Data.Enum;
using CarWorkShop.Models;
using System.ComponentModel.DataAnnotations;

namespace CarWorkShop.ViewModels
{
	public class EditUserViewModel
	{

		[Display(Name = "Name")]
		[Required(ErrorMessage = "Name is required")]
		public string Name { get; set; }
		[Display(Name = "Price")]
		[Required(ErrorMessage = "Price is required")]
		public string? Price { get; set; }

	}
}
