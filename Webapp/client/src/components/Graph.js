import React, { useState, useEffect } from "react";
import { Line } from "react-chartjs-2";

const Graph = () => {
    const [chartData, setChartData] = useState({});
    const [data, setData] = useState([]);

    const getData = async () => {
            const response = await fetch("http://localhost:5000/flowrates");
            const jsonData = await response.json();

        setData(jsonData);

        let flowrate = [];
        let time = [];

        for(const dataObj of data){
            flowrate.push(parseFloat(dataObj.gps));
            time.push(parseFloat(dataObj.time));
        }

        setChartData({
            labels: time,
            datasets: [{
                label: 'gps',
                data: flowrate,
                borderWidth: 4
            }]
        })
    }

    useEffect(() =>{
        getData();
    }, [])

    return(
        <div className="App">
            <h1>Flowrate</h1>
            <div style={{height: "800px", width: "800px"}}>
                <Line data={chartData} options={{
                    responsive: true,
                    title: {text: 'Flowrate', display: true},
                    scales: {
                        yAxes: [
                            {
                                ticks: {
                                    autoSkip: true,
                                    maxTicksLimit: 10,
                                    beginAtZero: true
                                }
                            }
                        ]
                    }
                }}/>
            </div>
        </div>
    )
};

export default Graph;