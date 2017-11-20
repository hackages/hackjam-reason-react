type action =
  | BookTextChange(string)
  | AddNewBook
  | SelectBook(int);

type state = {
  newBookText: string,
  selectedBookId: option(int)
};

let book = (book: Database.book, select, ~selectedBookId=?, delete) => {
  let safeSelectedBookId =
    switch selectedBookId {
    | None => 0
    | Some(id) => id
    };
  <tr
    key=(string_of_int(book.id))
    className=(book.id == safeSelectedBookId ? "is-selected" : "")
    onClick=select>
    <td> (Utils.ste(string_of_int(book.id))) </td>
    <td> (Utils.ste(book.title)) </td>
    <td> <a href=("#/detail/" ++ string_of_int(book.id))> (Utils.ste("View Details")) </a> </td>
    <td> <button className="button is-danger" onClick=delete> (Utils.ste("x")) </button> </td>
  </tr>
};

let component = ReasonReact.reducerComponent("Books");

let make = (~deleteBook, ~addBook, ~books, _children) => {
  ...component,
  initialState: (_) => {newBookText: "", selectedBookId: None},
  reducer: (action, state) =>
    switch action {
    | BookTextChange(newBookText) => ReasonReact.NoUpdate /* TODO */
    | AddNewBook => ReasonReact.UpdateWithSideEffects({...state, newBookText: ""}, ((_self) =>
                                                                    Js.log("book added?"))) /* TODO */
    | SelectBook(id) => ReasonReact.NoUpdate /* TODO */
    },
  render: ({state, reduce}) =>
    <div>
      <nav className="level">
        <div className="level-left">
          <div className="level-item">
            <p className="subtitle is-5">
              <strong> (Utils.ste("Book's")) </strong>
              (Utils.ste("title"))
            </p>
          </div>
          <div className="level-item">
            <div className="field has-addons">
              <p className="control">
                <input
                  className="input"
                  _type="text"
                  placeholder="books"
                  /* TODO */
                />
              </p>
              <p className="control">
                /* TODO */
                <button className="button"> (Utils.ste("Add")) </button>
              </p>
            </div>
          </div>
        </div>
      </nav>
      <table className="table">
        <thead>
          <tr>
            <th> <abbr title="ID"> (Utils.ste("ID")) </abbr> </th>
            <th> (Utils.ste("Title")) </th>
            <th> (Utils.ste("Details")) </th>
            <th> (Utils.ste("Delete")) </th>
          </tr>
        </thead>
        <tbody>
          (
            List.map(
              (bookItem) =>
                book(
                  bookItem,
                  reduce((_) => SelectBook(bookItem.id)),
                  ~selectedBookId=?state.selectedBookId,
                  (_) => deleteBook(bookItem.id)
                ),
              books
            )
            |> Array.of_list
            |> ReasonReact.arrayToElement
          )
        </tbody>
      </table>
    </div>
};
