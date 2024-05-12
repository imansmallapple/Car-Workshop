using CarWorkShop.Data.Enum;
using CarWorkShop.Models;
using Microsoft.AspNetCore.Identity;

namespace CarWorkShop.Data
{
    public class Seed
    {
        public static void SeedData(IApplicationBuilder applicationBuilder)
        {
            using (var serviceScope = applicationBuilder.ApplicationServices.CreateScope())
            {
                var context = serviceScope.ServiceProvider.GetService<ApplicationDbContext>();

                context.Database.EnsureCreated();

                if (!context.Tickets.Any())
                {
                    context.Tickets.AddRange(new List<Ticket>()
                    {
                        new Ticket()
                        {
                            Brand = "Alfa Romeo",
                            Description = "This is the description of the Alfa Romeo",
                            RegistrationId="326-JVA",
                            //TimeSlot="1:00-2:00",
                            Model ="Aston Martin",
                            EmployeeAssigned = "Join Smith",
                            StateCategory = StateCategory.Created,
                            RepairEstimate = new RepairEstimate()
                            {
                                Description = "Water",
                                cost = 114,
                                AttitudeCategory = AttitudeCategory.Accepted
                            }
                         },
                         new Ticket()
                        {
                            Brand = "Tesla",
                            Description = "This is the description of the Tesla",
                            RegistrationId="327-JVA",
                            //TimeSlot="1:00-2:00",
                            Model ="Fararri",
                            EmployeeAssigned = "Justin Biber",
                            StateCategory = StateCategory.Created,
                             RepairEstimate = new RepairEstimate()
                            {
                                Description = "Oil",
                                cost = 514,
                                AttitudeCategory = AttitudeCategory.Denied
                            }
                         },
                    });
                    context.SaveChanges();
                }
            }
        }

        public static async Task SeedUsersAndRolesAsync(IApplicationBuilder applicationBuilder)
        {
            using (var serviceScope = applicationBuilder.ApplicationServices.CreateScope())
            {
                //Roles
                var roleManager = serviceScope.ServiceProvider.GetRequiredService<RoleManager<IdentityRole>>();

                if (!await roleManager.RoleExistsAsync(UserRoles.Admin))
                    await roleManager.CreateAsync(new IdentityRole(UserRoles.Admin));
                if (!await roleManager.RoleExistsAsync(UserRoles.User))
                    await roleManager.CreateAsync(new IdentityRole(UserRoles.User));

                //Users
                var userManager = serviceScope.ServiceProvider.GetRequiredService<UserManager<User>>();
                string adminUserEmail = "adminuser@gmail.com";

                var adminUser = await userManager.FindByEmailAsync(adminUserEmail);
                if (adminUser == null)
                {
                    var newAdminUser = new User()
                    {
                        UserName = "superadmin",
                        Email = adminUserEmail,
                        EmailConfirmed = true,
                        Name ="Boss",
                    };
                    await userManager.CreateAsync(newAdminUser, "Coding@1234?");
                    await userManager.AddToRoleAsync(newAdminUser, UserRoles.Admin);
                }

                string appUserEmail = "user@etickets.com";

                var appUser = await userManager.FindByEmailAsync(appUserEmail);
                if (appUser == null)
                {
                    var newAppUser = new User()
                    {
                        UserName = "app-user",
                        Email = appUserEmail,
                        EmailConfirmed = true,
                        Name="John",
                    };
                    await userManager.CreateAsync(newAppUser, "Coding@1234?");
                    await userManager.AddToRoleAsync(newAppUser, UserRoles.User);
                }
            }
        }
    }
}