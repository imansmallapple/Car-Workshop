# Car-Workshop
Goal of the project is to implement an application for managing a car workshop using MVC architecture.
![image](https://github.com/imansmallapple/Car-Workshop/assets/82216261/31cdcf00-d5d3-49ce-9651-b97b9d2ad3fa)

## Contained functionality
### Employee management (done by 'admin' user)

* employees can be added or removed
* each employee has their calendar that displays when they are busy or available
* price of a single hour of work of a given employee
### Ticket management

* an employee (user of the application) can manage his calendar of the workshop (by adding/removing a hourly slots on given day)
they see available and occupied slots for repairs
* an employee can accept a ticket (request for repairs) by specifying his slots for given ticket - each ticket occupies one or more hourly slots. Assigned ticket changes state from 'created' to 'in progress')
* tickets can be moved between slots
* tickets have a state that can change in time (created/in progress/done/closed)
### Creating a ticket

A newly created ticket consists of:
* brand
* model
* registration id of a vehicle
* textual description of a problem
* employee assigned to repair the vehicle
* time slots when the repair is scheduled to happen
### Maintaining a ticket

During the lifetime of a ticket the following information might be added to the ticket:

estimate of the repair:
* description
* expected cost of service
* information if the estimate has already been accepted by the client
* list of parts bought for the repair - name/short description, e.g. "oil" - amount, e.g. "3.5" - unit price, e.g. "10.56"
total price (calculated automatically as amount * unit price), e.g. 36.96
* list of time slots and employees when the vehicle has actually been worked on
* price paid by the client

## Getting Started
1. Go into directory where you plan on keeping project and run.
```
  git fork https://github.com/imansmallapple/Car-Workshop.git
```
2. Create a local database.
3. Add connection string to app settings.json. It will look something like this:
```
  Data Source=DESKTOP-EI2TOGP\\SQLEXPRESS;Initial Catalog=Car-Workshop;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False
```
4. Register for a Cloudinary Account (%100 free) and add Cloudname, ApiKey, and Api secret to appsettings.json.
