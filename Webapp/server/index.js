const express = require("express");
const app = express();
const cors = require("cors");
const pool = require("./db");

//middleware
app.use(cors());
app.use(express.json());

//routes for server requests

//get all flowrates
app.get("/flowrates", async (req, res) => {
    try {
        const allFlowrates = await pool.query("SELECT * FROM flowrate");
        res.json(allFlowrates.rows);
    } catch (err) {
        console.error(err.message);
    }
});  

//get all pressures
app.get("/pressures", async (req, res) => {
    try {
        const allPressures = await pool.query("SELECT * FROM pressure");
        res.json(allPressures.rows);
    } catch (err) {
        console.error(err.message);
    }
});

//get all temperatures
app.get("/temperatures", async (req, res) => {
    try {
        const allTemperatures = await pool.query("SELECT * FROM temperature");
        res.json(allTemperatures.rows);
    } catch (err) {
        console.error(err.message);
    }
});

//get newest flowrate
app.get("/flowrates/newest", async (req, res) => {
    try {
      const newestFlowrate = await pool.query("SELECT * FROM flowrate ORDER BY time DESC LIMIT 1");
      res.json(newestFlowrate.rows);
    } catch (err) {
      console.error(err.message);
    }
  });

  //get newest pressure
app.get("/pressure/newest", async (req, res) => {
    try {
      const newestPressure = await pool.query("SELECT * FROM pressure ORDER BY time DESC LIMIT 1");
      res.json(newestPressure.rows);
    } catch (err) {
      console.error(err.message);
    }
  });

  //get newest temperature
app.get("/temperature/newest", async (req, res) => {
    try {
      const newestTemperature = await pool.query("SELECT * FROM temperature ORDER BY time DESC LIMIT 1");
      res.json(newestTemperature.rows);
    } catch (err) {
      console.error(err.message);
    }
  });

//get specific flowrate data point
app.get("/flowrates/:time", async (req, res) => {
    try {
        const { time } = req.params;
        const flowrate = await pool.query("SELECT * FROM flowrate WHERE time = $1", [time]);
        res.json(flowrate.rows[0]);
    } catch (err) {
        console.error(err.message);
    }
});

//get specific pressure data point
app.get("/pressures/:time", async (req, res) => {
    try {
        const { time } = req.params;
        const pressure = await pool.query("SELECT * FROM pressure WHERE time = $1", [time]);
        res.json(pressure.rows[0]);
    } catch (err) {
        console.error(err.message);
    }
});

//get specific temperature data point
app.get("/temperatures/:time", async (req, res) => {
    try {
        const { time } = req.params;
        const temperature = await pool.query("SELECT * FROM temperature WHERE time = $1", [time]);
        res.json(temperature.rows[0]);
    } catch (err) {
        console.error(err.message);
    }
});

//delete flowrate data point
app.delete("/flowrates/:time", async (req, res) => {
    try {
        const { time } = req.params;
        const deleteFlowrate = await pool.query("DELETE FROM flowrate WHERE time = $1", [time]);
        res.json("Flowrate was deleted!");
    } catch (err) {
        console.error(err.message);
    }
});

//delete pressure data point
app.delete("/pressures/:time", async (req, res) => {
    try {
        const { time } = req.params;
        const deletePressure = await pool.query("DELETE FROM pressure WHERE time = $1", [time]);
        res.json("Pressure was deleted!");
    } catch (err) {
        console.error(err.message);
    }
});

//delete temperature data point
app.delete("/temperatures/:time", async (req, res) => {
    try {
        const { time } = req.params;
        const deleteTemperature = await pool.query("DELETE FROM temperature WHERE time = $1", [time]);
        res.json("Temperature was deleted!");
    } catch (err) {
        console.error(err.message);
    }
});

//get constraints
app.get("/constraints/", async (req, res) => {
    try {
      const constraints = await pool.query("SELECT * FROM constraints LIMIT 1");
      res.json(constraints.rows);
    } catch (err) {
      console.error(err.message);
    }
  });

//update minflow
app.put("/constraints/minflow", async (req, res) => {
  try {
    const { minflowrate } = req.body;
    const updateParam = await pool.query(
      "UPDATE constraints SET minflowrate = $1",
      [minflowrate]
    );

    res.json("minflow was updated!");
  } catch (err) {
    console.error(err.message);
  }
});

//update maxflow
app.put("/constraints/maxflow", async (req, res) => {
  try {
    const { maxflowrate } = req.body;
    const updateParam = await pool.query(
      "UPDATE constraints SET maxflowrate = $1",
      [maxflowrate]
    );

    res.json("maxflowrate was updated!");
  } catch (err) {
    console.error(err.message);
  }
});

//update minpressure
app.put("/constraints/minpressure", async (req, res) => {
  try {
    const { minpressure } = req.body;
    const updateParam = await pool.query(
      "UPDATE constraints SET minpressure = $1",
      [minpressure]
    );

    res.json("minpressure was updated!");
  } catch (err) {
    console.error(err.message);
  }
});

//update maxpressure
app.put("/constraints/maxpressure", async (req, res) => {
  try {
    const { maxpressure } = req.body;
    const updateParam = await pool.query(
      "UPDATE constraints SET maxpressure = $1",
      [maxpressure]
    );

    res.json("maxpressure was updated!");
  } catch (err) {
    console.error(err.message);
  }
});

//update mintemp
app.put("/constraints/mintemp", async (req, res) => {
  try {
    const { mintemp } = req.body;
    const updateParam = await pool.query(
      "UPDATE constraints SET mintemp = $1",
      [mintemp]
    );

    res.json("mintemp was updated!");
  } catch (err) {
    console.error(err.message);
  }
});

//update maxtemp
app.put("/constraints/maxtemp", async (req, res) => {
  try {
    const { maxtemp } = req.body;
    const updateParam = await pool.query(
      "UPDATE constraints SET maxtemp = $1",
      [maxtemp]
    );

    res.json("maxtemp was updated!");
  } catch (err) {
    console.error(err.message);
  }
});

//app runs on localhost
app.listen(5000, () => {
    console.log("server has started on port 5000");
});