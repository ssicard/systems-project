import {SELECT_LOG, APPLY_FILTER, CLEAR_FILTER, LOAD_LOGS_SUCCESS} from '../constants';
const initialState={
    allLogs:[
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client C",
            guid: '0'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client D",
            recipient: "Client B",
            guid: '2'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '3'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '4'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '5'
        },
        {
            timestamp:(new Date(2000,1,1,1,1,1,1)).toISOString(),
            sender: "Client E",
            recipient: "ClientFB",
            guid: '6'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '7'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '8'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '9'
        },
    ],
    displayedLogs: [
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client C",
            guid: '0'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client D",
            recipient: "Client B",
            guid: '2'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '3'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '4'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '5'
        },
        {
            timestamp:(new Date(2000,1,1,1,1,1,1)).toISOString(),
            sender: "Client E",
            recipient: "ClientFB",
            guid: '6'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '7'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '8'
        },
        {
            timestamp:(new Date).toISOString(),
            sender: "Client A",
            recipient: "Client B",
            guid: '9'
        },
    ]   
}
export default function logs(state = initialState, action) {
    switch (action.type) {
      case APPLY_FILTER:
        var newDisplayedLogs = [...state.allLogs];
        newDisplayedLogs = newDisplayedLogs.filter((log)=>{
            var logTime = new Date(log.timestamp).getTime();
            return logTime >= action.payload.startRange &&
                   logTime <= action.payload.endRange &&
                   (action.payload.sender=="" || log.sender==action.payload.sender) &&
                   (action.payload.recipient=="" || log.recipient==action.payload.recipient);
        });
        return {...state,displayedLogs:newDisplayedLogs};
      case LOAD_LOGS_SUCCESS:
        return state;//TODO -- set the state to the new logs that have been loaded.
      case CLEAR_FILTER:
        return {allLogs: state.allLogs, displayedLogs: state.allLogs};
      default:
        return state
    }
  }