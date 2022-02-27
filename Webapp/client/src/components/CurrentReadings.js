import React, { Fragment, useEffect, useState } from "react";

const CurrentReadings = () => {

    const [flows, setFlows] = useState([]);
    
    const getFlows = async ()  => {
        try {
          const response = await fetch(`http://localhost:5000/flowrates/newest`);
          const jsonData = await response.json();
    
          setFlows(jsonData);
        } catch (err) {
          console.error(err.message);
        }
      };

    const [pressures, setPressure] = useState([]);
    
    const getPressure = async ()  => {
        try {
          const response = await fetch(`http://localhost:5000/pressure/newest`);
          const jsonData = await response.json();
    
          setPressure(jsonData);
        } catch (err) {
          console.error(err.message);
        }
      };

    const [temps, setTemps] = useState([]);
    
    const getTemps = async ()  => {
        try {
          const response = await fetch(`http://localhost:5000/temperature/newest`);
          const jsonData = await response.json();
    
          setTemps(jsonData);
        } catch (err) {
          console.error(err.message);
        }
      };

    useEffect(() => {
      getFlows();
      getPressure();
      getTemps();

      const interval = setInterval(() => {
        getFlows();
        getPressure();
        getTemps();
      }, 1000);

    }, []);

    return (
        <Fragment>
            <h2 className="text-center mt-5">Current Readings</h2>
            <table class="table mt-5 text-center">
            <tr>
                <th>Flowrate (gps)</th>
                <th>Pressure (psi)</th>
                <th>Temperature (F)</th>
            </tr>
            <tbody>
              
                <tr>
                    {flows.map(flow => (
                        <td>{flow.gps}</td>
                    ))}
                  
                     {pressures.map(pressure => (
                        <td>{pressure.psi}</td>
                    ))}
                    {temps.map(temp => (
                        <td>{temp.tempf}</td>
                    ))}
                </tr>
              
            </tbody>
            </table>
            
            {/*
            {flows.map(flow => (
                <form>
                <textarea value={flow.description}/>
            </form>
              ))}
            */}

        </Fragment>
    );
};

export default CurrentReadings;