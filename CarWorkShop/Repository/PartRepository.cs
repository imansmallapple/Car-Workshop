using CarWorkShop.Data;
using CarWorkShop.Data.Interfaces;
using CarWorkShop.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.EntityFrameworkCore;
using System.Net.Sockets;

namespace CarWorkShop.Repository
{
    public class PartRepository : IPartRepository
    {
        private readonly ApplicationDbContext _context;
        private readonly IHttpContextAccessor _httpContextAccessor;

        public PartRepository(ApplicationDbContext context, IHttpContextAccessor httpContextAccessor)
        {
            _context = context;
            _httpContextAccessor = httpContextAccessor;
        }
        public async Task<List<Part>> GetTicketAllParts(int ticketId)
        {
            var ticketParts = _context.Parts.Where(p => p.TicketId == ticketId);
            return await ticketParts.ToListAsync();
        }
        public bool Add(Part part)
        {
            _context.Add(part);
            return Save();
        }

        public bool Delete(Part part)
        {
            _context.Remove(part);
            return Save();
        }


        public bool Save()
        {
            var saved = _context.SaveChanges();
            return saved > 0 ? true : false;
        }

        public bool Update(Part part)
        {
            _context.Update(part);
            return Save();
        }
    }
}
