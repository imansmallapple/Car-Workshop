using Microsoft.AspNetCore.Mvc;
using CarWorkShop.Data.Interface;
using CarWorkShop.ViewModels;
using CarWorkShop.Data.Interfaces;
using CarWorkShop.Data;
using CarWorkShop.Models;
using Microsoft.AspNetCore.Identity;
using CarWorkShop.Repository;
using Microsoft.EntityFrameworkCore;

namespace RunGroopWebApp.Controllers
{
    public class UserController : Controller
    {
        private readonly IUserRepository _userRepository;
		private readonly UserManager<User> _userManager;

		public UserController(IUserRepository userRepository, UserManager<User> userManager)
        {
            _userRepository = userRepository;
			_userManager = userManager;
		}
        [HttpGet]
        public async Task<IActionResult> Index()
        {
            var users = await _userRepository.GetAllUsers();
            List<UserViewModel> result = new List<UserViewModel>();
            foreach (var user in users)
            {
                var userViewModel = new UserViewModel
                {
                    Id = user.Id,
                    UserName = user.UserName,
                    Price = user.Price,
                };
                result.Add(userViewModel);
            }
            return View(result);
		}
        //      [HttpGet]
        //public async Task<IActionResult> Detail(string id)
        //      {
        //          var user = await _userRepository.GetUserByIdAsync(id);
        //          var userDetailViewModel = new UserDetailViewModel()
        //          {
        //              Id = user.Id,
        //              UserName = user.UserName,
        //              Price = user.Price,
        //          };
        //          return View(userDetailViewModel);
        //      }
        [HttpGet]
        public async Task<IActionResult> Detail(string id)
        {
            var user = await _userRepository.GetUserByIdAsync(id);
            return View(user);
        }
        [HttpGet]
        public async Task<IActionResult> Create()
        {
            var createEmployeeViewModel = new CreateUserViewModel();
            return View(createEmployeeViewModel);
        }
        [HttpPost]
        public async Task<IActionResult> Create(CreateUserViewModel createUserViewModel)
        {

            if (!ModelState.IsValid) return View(createUserViewModel);
            var user = await _userManager.FindByEmailAsync(createUserViewModel.EmailAddress);
            //check data base if has the user or not
            if (user != null)
            {
                TempData["Error"] = "This email address is already in use";
                return View(createUserViewModel);
            }
            var newUser = new User()
            {
                Email = createUserViewModel.EmailAddress,
                Name = createUserViewModel.Name,
                UserName = createUserViewModel.Name,
                Price = createUserViewModel.Price,
            };
            var newUserResponse = await _userManager.CreateAsync(newUser, createUserViewModel.Password);
            if (newUserResponse.Succeeded)
                await _userManager.AddToRoleAsync(newUser, UserRoles.User);

            return RedirectToAction("Index", "User");
        }
		public async Task<IActionResult> Edit(string id)
		{
			var user = await _userRepository.GetUserByIdAsync(id);
			var editVM = new EditUserViewModel
			{
				Name = user.Name,
                Price = user.Price,
			};
			return View(editVM);
		}
		[HttpPost]
		public async Task<IActionResult> Edit(string id, EditUserViewModel userVM)
		{
			if (!ModelState.IsValid)
			{
				ModelState.AddModelError("", "Failed to edit user");
				return View("Edit", userVM);
			}

			var user = await _userRepository.GetUserByIdAsync(id); // Fetch the user from the database

			if (user == null)
			{
				ModelState.AddModelError("", "User not found");
				return View("Edit", userVM);
			}

			user.Name = userVM.Name;
			user.Price = userVM.Price;
			user.Email = "HAHAHA";

			try
			{
				_userRepository.Update(user);
			}
			catch (DbUpdateConcurrencyException)
			{
				ModelState.AddModelError("", "Failed to edit user. The user may have been modified or deleted since entities were loaded.");
				return View("Edit", userVM);
			}

			return RedirectToAction("Index", "User");
		}
        [HttpGet]
        public async Task<IActionResult> Delete(string id)
        {
			var userDetails = await _userRepository.GetUserByIdAsync(id);
			if (userDetails == null) return View("Error");
			return View(userDetails);
		}
        [HttpPost, ActionName("Delete")]
        public async Task<IActionResult> DeleteUser(string id)
        {
			var userDetails = await _userRepository.GetUserByIdAsync(id);
			if (userDetails == null) return View("Error");
			_userRepository.Delete(userDetails);
			return RedirectToAction("Index");
		}
        [HttpGet]
        public async Task<IActionResult> AcceptTicket(string id)
        {
            return View();
        }
	}
}
