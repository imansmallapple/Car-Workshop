using CarWorkShop.Models;

namespace CarWorkShop.ViewModels
{
    public class UserDetailViewModel
    {
        public string Id { get; set; }
        public string UserName { get; set; }
        public string? Price { get; set; }
        //public string name { get; set; }
        public Calender? Calender { get; set; }
    }
}
