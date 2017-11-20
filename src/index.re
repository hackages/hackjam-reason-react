/*
   Import css styles: custom and Bulma library
   Interop with Javascript with BuckleScript syntax
 */
[%%bs.raw {|require('./css/index.css')|}];

[%%bs.raw {|require('bulma/css/bulma.css')|}];

/*
   Helper function to render a route.
   Notice that we use ReactDOM.render equivalent from ReactJS called
   'ReactDOMRe.renderToElementWithId', which takes:
   - as 1st argument: the Reason component
   - as 2nd argument: the id of the div to render the Reason component
 */
let renderForRoute = (route) => ReactDOMRe.renderToElementWithId(<App route />, "root");

/*
   We are using 'Director' as a mature routing library
   which also has binding to Reason/BuckleScript named 'bs-director'.
   An explanation can be found here:
   https://github.com/reasonml-community/bs-director
 */
let router =
  DirectorRe.makeRouter({
    "/": "dashboard",
    "/manage-books": "manage-books",
    "/detail/:bookId": "bookdetail"
  });

let handlers = {
  "dashboard": () => renderForRoute(DashBoardRoute),
  "bookdetail": (bookId: string) => renderForRoute(BookDetailsRoute(bookId)),
  "manage-books": () => renderForRoute(ManageBooksRoute)
};

DirectorRe.configure(router, {"resource": handlers});

DirectorRe.init(router, "/");
