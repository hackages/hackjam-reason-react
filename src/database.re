type book = {
  id: int,
  title: string,
  description: string,
  category: string
};

type books = list(book);

/*
   This is our mock database.
   It will avoid you to write async code for now
 */
let books = [
  {
    id: 1,
    title: "A good book",
    description: "A very good book needs a very good description",
    category: "Awesomeness"
  },
  {
    id: 2,
    title: "A bad book",
    description: "A very bad book needs a very bad description",
    category: "Badness"
  }
];
