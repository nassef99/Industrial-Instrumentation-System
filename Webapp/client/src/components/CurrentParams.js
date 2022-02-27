import React, { Fragment, useEffect, useState } from "react";
import EditFlowParams from "./EditFlowParams";
import EditPressureParams from "./EditPressureParams";
import EditTempParams from "./EditTempParams";

const CurrentParams = () => {

    const [constraints, setConstraints] = useState([]);
    
    const getConstraints = async ()  => {
        try {
          const response = await fetch(`http://localhost:5000/constraints/`);
          const jsonData = await response.json();
    
          setConstraints(jsonData);
        } catch (err) {
          console.error(err.message);
        }
      };

    useEffect(() => {
        getConstraints();
        
    }, []);

    return (
        <Fragment>
            <h2 className="text-center mt-5">Current Parameters</h2>
            <table class="table mt-5 text-center">
            <tr>
                <th> </th>
                <th>Min</th>
                <th>Max</th>
                <th> </th>
            </tr>
            {constraints.map(constraint => (
                <tr>
                    <th>Flowrate (gps)</th>
                    <td>{constraint.minflowrate}</td>
                    <td>{constraint.maxflowrate}</td>
                    <td><EditFlowParams constraint={constraint} /></td>

                </tr>

            ))}
            {constraints.map(constraint => (
                <tr>
                    <th>Pressure (psi)</th>
                    <td>{constraint.minpressure}</td>
                    <td>{constraint.maxpressure}</td>
                    <td><EditPressureParams constraint={constraint} /></td>

                </tr>

            ))}
            {constraints.map(constraint => (
                <tr>
                    <th>Temperature (F)</th>
                    <td>{constraint.mintemp}</td>
                    <td>{constraint.maxtemp}</td>
                    <td><EditTempParams constraint={constraint} /></td>

                </tr>

            ))}
            </table>

        </Fragment>
    );
};

export default CurrentParams;