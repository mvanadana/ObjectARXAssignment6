# ObjectARXAssignment6
## Step through All Objects in the Database
This ObjectARX application has a 'listObjects' function that retrieves and showcases the class names of all objects in the current AutoCAD drawing space. Here's what it does:

Obtain Database:

Gets the drawing's database.
Retrieve Current Space:

Accesses the current space object (Model Space or Paper Space).
Iterate Through Objects:

Goes through each object in the current space.
Display Class Names:

Shows the class name for each object.
Close Entities:

Closes each entity after displaying its class name.
Close Current Space:

Closes the current space object.
Delete Block Iterator:

Removes the block iterator from memory.
Display in AutoCAD Text Window:

Prints the class names in the AutoCAD Text Window.
