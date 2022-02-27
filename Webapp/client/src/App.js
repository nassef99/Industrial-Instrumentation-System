import React,  { Fragment } from "react";
import './App.css';

//components
import Header from "./components/Header";
import CurrentReadings from "./components/CurrentReadings";
import ListFlowData from "./components/ListFlowData";
import ListPressureData from "./components/ListPressureData";
import ListTempData from "./components/ListTempData";
import CurrentParams from "./components/CurrentParams";
/*import Graph from "./components/Graph";*/


function App() {
  return (
    <Fragment>
      <div className="container">

        <Header />
        <CurrentReadings />
        {/*<Graph />*/}
        <CurrentParams />
        <ListFlowData />
        <ListPressureData />
        <ListTempData />        

      </div>
    </Fragment>
  );
}

export default App;
