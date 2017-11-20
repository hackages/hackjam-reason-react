let component = ReasonReact.statelessComponent("Navbar");

let make = (~books, _children) => {
  ...component,
  render: (_self) =>
    <nav className="navbar">
      <div className="navbar-brand">
        <div className="navbar-item">
          <img src="./images/hackages.jpg" alt="Logo" width="112" height="28" />
        </div>
        <div className="navbar-item"> <h1> <span> Bookstore /* Looks like something is wrong here */ </span> </h1> </div>
      </div>
      <div id="navmenuMobile" className="navbar-menu is-active">
        <div className="navbar-start">
          <p className="navbar-item"> <a href="#/"> Dashboard </a> </p>
          <div className="navbar-item"> <p> <a href="#/manage-books"> Manage Books </a> </p> </div>
        </div>
        <div
          className="navbar-end"
          /* TODO add BookSearch component */
        />
      </div>
    </nav>
};
