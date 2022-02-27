import React, { Fragment, useState } from "react";

const EditPressureParams = ({ constraint }) => {

    const [minpressure , setminpressure] = useState(constraint.minpressure);
    const [maxpressure , setmaxpressure] = useState(constraint.maxpressure);

    //edit param function
    
    const updateParam = async (e) => {
        e.preventDefault();
        try {
            const body1 = { minpressure };
            const response1 = await fetch("http://localhost:5000/constraints/minpressure", {
                method: "PUT",
                headers: {"Content-Type": "application/json"},
                body: JSON.stringify(body1)
            });

            const body2 = { maxpressure };
            const response2 = await fetch("http://localhost:5000/constraints/maxpressure", {
                method: "PUT",
                headers: {"Content-Type": "application/json"},
                body: JSON.stringify(body2)
            });




            window.location = "/";
        } catch (err) {
            console.error(err.message);
        }
    }

    return <Fragment>
        <button type="button" class="btn btn-warning" data-toggle="modal" data-target="#pressureparam">
        Edit
        </button>

        <div class="modal" id="pressureparam">
            <div class="modal-dialog">
                <div class="modal-content">

                <div class="modal-header">
                    <h4 class="modal-title">Edit Pressure Parameters (psi)</h4>
                    <button type="button" class="close" data-dismiss="modal">&times;</button>
                </div>

                <div class="modal-body">
                    Min: <input type="text" className="form-control" value={minpressure} onChange={e => setminpressure(e.target.value)} />
                    Max: <input type="text" className="form-control" value={maxpressure} onChange={e => setmaxpressure(e.target.value)} />
                </div>

                <div class="modal-footer">
                    <button type="button" class="btn btn-warning" data-dismiss="modal" onClick = {e => updateParam(e)}>Edit</button>
                    <button type="button" class="btn btn-danger" data-dismiss="modal">Close</button>

                </div>

                </div>
            </div>
        </div>
    </Fragment>
};

export default EditPressureParams;