import React, { Fragment, useState } from "react";

const EditTempParams = ({ constraint }) => {

    const [mintemp , setmintemp] = useState(constraint.mintemp);
    const [maxtemp , setmaxtemp] = useState(constraint.maxtemp);

    //edit param function
    
    const updateParam = async (e) => {
        e.preventDefault();
        try {
            const body1 = { mintemp };
            const response1 = await fetch("http://localhost:5000/constraints/mintemp", {
                method: "PUT",
                headers: {"Content-Type": "application/json"},
                body: JSON.stringify(body1)
            });

            const body2 = { maxtemp };
            const response2 = await fetch("http://localhost:5000/constraints/maxtemp", {
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
        <button type="button" class="btn btn-warning" data-toggle="modal" data-target="#tempparam">
        Edit
        </button>

        <div class="modal" id="tempparam">
            <div class="modal-dialog">
                <div class="modal-content">

                <div class="modal-header">
                    <h4 class="modal-title">Edit Temperature Parameters (F)</h4>
                    <button type="button" class="close" data-dismiss="modal">&times;</button>
                </div>

                <div class="modal-body">
                    Min: <input type="text" className="form-control" value={mintemp} onChange={e => setmintemp(e.target.value)} />
                    Max: <input type="text" className="form-control" value={maxtemp} onChange={e => setmaxtemp(e.target.value)} />
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

export default EditTempParams;