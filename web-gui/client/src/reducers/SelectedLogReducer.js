import {SELECT_LOG, EXPAND_LOG} from '../constants';
const initialState={
    selectedLog: -1,
    expandedLogs: [],
}
export default function selectedLog(state = initialState, action) {
    switch (action.type) {
      case SELECT_LOG:
        return {selectedLog: action.payload, expandedLogs: state.expandedLogs};
      case EXPAND_LOG:
        console.log('adding '+action.payload+" to the array.");
        console.log(action.payload);
        console.log(state.expandedLogs);
        let newExpandedLogs = [...state.expandedLogs];
        if(newExpandedLogs.includes(action.payload)){
          newExpandedLogs.splice(newExpandedLogs.indexOf(action.payload),1);
        } else{
          newExpandedLogs.push(action.payload);
        }
        console.log(newExpandedLogs);
        return {selectedLog: state.selectedLog, expandedLogs: newExpandedLogs};
      default:
        return state
    }
  }