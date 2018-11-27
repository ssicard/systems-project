import {SELECT_LOG, APPLY_FILTER, CLEAR_FILTER, LOAD_LOGS_SUCCESS, CREATE_LOGS} from '../constants';
const initialState={
    displayedLogs:[]
}
export default function logs(state = initialState, action) {
    switch (action.type) {
      case CREATE_LOGS:
        console.log(action.payload);
        let newLogs = action.payload.requests.map((el)=>{
            return {
                ...el,
                responses: action.payload.responses.filter((res)=>{return res.responseTo == el.guid;}),
            }
        });
        return {allLogs: newLogs, displayedLogs: newLogs};
      case APPLY_FILTER:
        var newDisplayedLogs = [...state.allLogs];
        newDisplayedLogs = newDisplayedLogs.filter((log)=>{
            var logTime = new Date(log.timestamp).getTime();
            console.log('current log');
            console.log(log);
            console.log('current filter');
            console.log(action.payload);
            console.log('filtered responses');
            console.log(log.responses.filter((res)=>{return res.sender==action.payload.response}));
            console.log(logTime >= action.payload.startRange);
           // console.log(logTime <= action.payload.endRange);
            console.log((action.payload.request=="" || log.sender==action.payload.request));
            console.log((action.payload.response=="" || log.responses.filter((res)=>{return res.sender==action.payload.response}).length>0));
            return logTime >= action.payload.startRange &&
                  // logTime <= action.payload.endRange &&
                   (action.payload.request=="" || log.sender==action.payload.request) &&
                   (action.payload.response=="" || log.responses.filter((res)=>{return res.sender==action.payload.response}).length>0);
        });
        return {...state,displayedLogs:newDisplayedLogs};
      case CLEAR_FILTER:
        return {allLogs: state.allLogs, displayedLogs: state.allLogs};
      default:
        return state
    }
  }