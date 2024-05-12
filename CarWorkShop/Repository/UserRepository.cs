using CarWorkShop.Data;
using CarWorkShop.Data.Interfaces;
using CarWorkShop.Models;
using Microsoft.EntityFrameworkCore;
using System.Net.Sockets;

namespace CarWorkShop.Repository
{
    public class UserRepository : IUserRepository
    {
        private readonly ApplicationDbContext _context;

        public UserRepository(ApplicationDbContext context)
        {
            _context = context;
        }
        public bool Add(User user)
        {
            throw new NotImplementedException();
        }

        public bool Delete(User user)
        {
			_context.Remove(user);
			return Save();
		}

        public async Task<IEnumerable<User>> GetAllUsers()
        {
            return await _context.Users.ToListAsync();
        }

        public async Task<User> GetUserByIdAsync(string id)
        {
            return await _context.Users.Include(i => i.Calender).FirstOrDefaultAsync(u => u.Id == id);
        }
        public bool Save()
        {
            var saved = _context.SaveChanges();
            return saved > 0 ? true : false;
        }

        public bool Update(User user)
        {
            _context.Update(user);
            return Save();
        }
    }
}
