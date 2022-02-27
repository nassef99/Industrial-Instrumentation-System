import React, { Fragment, useState } from "react";

const EditFlowParams = ({ constraint }) => {

    const [minflowrate , setminflowrate] = useState(constraint.minflowrate);
    const [maxflowrate , setmaxflowrate] = useState(constraint.maxflowrate);

    //edit param function
    
    const updateParam = async (e) => {
        e.preventDefault();
        try {
            const body1 = { minflowrate };
            const response1 = await fetch("http://localhost:5000/constraints/minflow", {
                method: "PUT",
                headers: {"Content-Type": "application/json"},
                body: JSON.stringify(body1)
            });

            const body2 = { maxflowrate };
            const response2 = await fetch("http://localhost:5000/constraints/maxflow", {
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
        <button type="button" class="btn btn-warning" data-toggle="modal" data-target="#flowrateparam">
        Edit
        </button>

        <div class="modal" id="flowrateparam">
            <div class="modal-dialog">
                <div class="modal-content">

                <div class="modal-header">
                    <h4 class="modal-title">Edit Flowrate Parameters (gps)</h4>
                    <button type="button" class="close" data-dismiss="modal">&times;</button>
                </div>

                <div class="modal-body">
                    Min: <input type="text" className="form-control" value={minflowrate} onChange={e => setminflowrate(e.target.value)} />
                    Max: <input type="text" className="form-control" value={maxflowrate} onChange={e => setmaxflowrate(e.target.value)} />
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

export default EditFlowParams;