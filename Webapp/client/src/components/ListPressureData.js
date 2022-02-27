import React, { Fragment, useEffect, useState } from "react";

const ListPressureData = () => {

    const [data, setData] = useState([]);

    //delete data function

    const deleteData = async time => {
        try {
          const deleteData = await fetch(`http://localhost:5000/pressures/${time}`, {
            method: "DELETE"
          });

          setData(data.filter(data => data.time !== time));
        } catch (err) {
          console.error(err.message);
        }
      };
    
    const getData = async () => {
        try {
            const response = await fetch("http://localhost:5000/pressures");
            const jsonData = await response.json();

            setData(jsonData);
        } catch (err) {
            console.error(err.message);
        }
    };

    useEffect(() => {
        getData();
    }, []);

    return (
        <Fragment>
            <a data-toggle="modal" style={{
          display: "flex",
          justifyContent: "center",
          alignItems: "center"
        }} href="#PressureModal" class="btn btn-primary btn-lg">View Full Pressure Data</a>

            <div class="modal fade" id="PressureModal">
            <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                <h4 class="modal-title">Pressure Data</h4>
                </div>
                <div class="modal-body">
                <table class="table mt-5 text-center">
            <thead>
                <tr>
                    <th>Value</th>
                    <th>Timestamp</th>
                    <th>Delete</th>
                </tr>
            </thead>
            <tbody>
                {data.map(data => (
                    <tr key={data.time}>
                        <td>{data.psi}</td>
                        <td>{data.time}</td>
                        <td>
                            <button 
                            className="btn btn-danger" 
                            onClick={() => deleteData(data.time)}>
                                Delete
                            </button>
                        </td>
                    </tr>
                ))}
            </tbody>
            </table>
                </div>
                <div class="modal-footer">
                <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
                </div>
            </div>
            </div>
            </div>
            
        </Fragment>
    );
};

export default ListPressureData;