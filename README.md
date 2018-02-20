## HackJam: ReasonReact

#### Getting started 

```
npm install
npm start
```
This will open Chrome and launch your application   
(You are running reason-scripts which has bindings on react-scripts)

### Before you start
Notice that each file translates to a Module in Reason. 
So if you declare a `bar` variable in `foo.re`, you will be able to access it, in another file, like so: `Foo.bar`.

### Todo

#### Take a look at the utils.re file. 
We assigned `ReasonReact.stringToElement` to `ste`, so you can use `Utils.ste` easily in other files. (Less verbose)
We also have a helper function to transform an event from an input text to the value it contains. (You will need it at the end of the HackJam)

#### Take a look at dababase.re file
This is our mock database we will use. It contains the data and the types of our database.

#### Fix the bugs
##### 1. app.re
By fixing this bug, you will understand how JSX calls a function under the hood.
When, in the `index.re`, we call `<App route/>` this is actually calling the `make` function of the `app.re` file.

##### 2. navbar.re
ReasonML won't let you have runtime errors. To do so, everything should be typed. 
Even simple text in a JSX tag.

##### 3. bookDetail.re
Define the kind of actions this component has. (Only fix the first TODO in this file!)
In Reason, we define them with Variants https://reasonml.github.io/guide/language/variant. 
e.g.:   
```
type actions = 
   | Click
   | Send(string)
   | Send(string, int);
```
Note: You will have to use the `Database.book` type here.

#### Add features

##### 4. dashboard.re
Display all books by mapping on each book and calling the `book` function, which displays a single book.
The `book` function misses some text!
To display a list of books,   
you need to transform your list to an array (Array docs)[https://reasonml.github.io/api/Array.html] 
and then translate that array in a ReasonReact component (ReasonReact render docs)[https://reasonml.github.io/reason-react/docs/en/render.html]

You should also fix the `href` in the `book` function.
If you click on a book in the browser, you won't be redirected to the book detail because you're still missing the implementation in app.re. Let's do that in the next step.

##### app.re

Add the navbar Component (Notice how easy imports are)

You notice that the `switch` on the `route` only handles the `DashBoardRoute`.

Let's add the `BookDetailsRoute`. For now don't implement the save method. You can mock it like this: `save=(fun book => ())`
You should now be able to go to the book details.

Let's now add the `ManageBooksRoute`. Again, mock the `add` and `delete` functions for now.

Let's now fix the reducer (reducer docs)[https://reasonml.github.io/reason-react/docs/en/state-actions-reducer.html]
First implement the delete, then update and add.

##### navbar.re

Add the BookSearch component

##### bookSeach.re
Transform in reducerComponent: 
  - state type
  - initialState
  - reducer function
  - action types
add input element
display found elements
replace className with logic commented

##### manageBooks.re
Fix all reducer functions
Fix input element to update title
Fix add button

##### bookDetails.re
If the bookSearch component works, you'll see there's a bug:
- Look for a book, click on it to see the details
- look for another book, click on it to see the details
You will see that the book is not updated. 
You need to handle the `didUpdate` lifeCycle function. When the previous property id changed, send an action to add this new book to the component state.
 To do so, you'll need `retainedProps`:
Transform your component in `reducerComponentWithRetainedProps`: add retained property and `didUpdate`lifecycle.


#### Ressources:

Reason: https://reasonml.github.io/   
ReasonReact: https://reasonml.github.io/reason-react/  

(Should not be necessary)   
BuckleScript: https://bucklescript.github.io/bucklescript/Manual.html
