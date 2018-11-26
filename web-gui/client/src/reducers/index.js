import { combineReducers } from 'redux';
import selectedLog from './SelectedLogReducer';
import messages from './MessageReducer';
import logs from './LogReducer';
import filter from './FilterReducer';
import loadState from './LoadStateReducer';
import requests from './RequestReducer';
import responses from './ResponseReducer';
export default combineReducers({
    selectedLog:selectedLog,
    messages:messages,
    logs:logs,
    filter:filter,
    loadState: loadState,
    requests: requests,
    responses: responses,
});