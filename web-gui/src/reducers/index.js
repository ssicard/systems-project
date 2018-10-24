import { combineReducers } from 'redux';
import selectedLog from './SelectedLogReducer';
import messages from './MessageReducer';
import logs from './LogReducer';
import filter from './FilterReducer';
import loadState from './LoadStateReducer';
export default combineReducers({
    selectedLog:selectedLog,
    messages:messages,
    logs:logs,
    filter:filter,
    loadState: loadState,
});