# Car-Workshop
Goal of the project is to implement an application for managing a car workshop.
## Contained functionality
### Employee management (done by 'admin' user)

employees can be added or removed
each employee has their calendar that displays when they are busy or available
price of a single hour of work of a given employee
### Ticket management

an employee (user of the application) can manage his calendar of the workshop (by adding/removing a hourly slots on given day)
they see available and occupied slots for repairs
an employee can accept a ticket (request for repairs) by specifying his slots for given ticket - each ticket occupies one or more hourly slots. Assigned ticket changes state from 'created' to 'in progress')
tickets can be moved between slots
tickets have a state that can change in time (created/in progress/done/closed)
### Creating a ticket

A newly created ticket consists of:
brand
model
registration id of a vehicle
textual description of a problem
employee assigned to repair the vehicle
time slots when the repair is scheduled to happen
### Maintaining a ticket

During the lifetime of a ticket the following information might be added to the ticket:

estimate of the repair:
description
expected cost of service
information if the estimate has already been accepted by the client
list of parts bought for the repair - name/short description, e.g. "oil" - amount, e.g. "3.5" - unit price, e.g. "10.56"
total price (calculated automatically as amount * unit price), e.g. 36.96
list of time slots and employees when the vehicle has actually been worked on
price paid by the client
