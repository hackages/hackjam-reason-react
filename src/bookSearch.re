let bookResultItem = (book: Database.book) =>
  <a
    key=(string_of_int(book.id))
    href=("#/detail/" ++ string_of_int(book.id))
    className="navbar-item">
    (Utils.ste(book.title))
  </a>;

let component = ReasonReact.statelessComponent("BookSearch");

let make = (~books, _children) => {
  ...component,
  render: ({reduce, state}) =>
    /*
       className below logic once you have a reducerComponent
       List.length state.books > 0 ? "navbar-item is-active" : "navbar-item"
     */
    <div className="replace this by the above comment logic">
      <div
        className="field is-grouped"
        /* TODO: input element */
      />
      <div className="navbar-dropdown">
        /*
           TODO: display found elements,
           display each element with the bookResultItem function
         */
         <a className="navbar-item"> (Utils.ste("BOOK")) </a> </div>
    </div>
};
