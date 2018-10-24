import {SELECT_LOG, APPLY_FILTER, LOAD_LOGS_PENDING, LOAD_LOGS_SUCCESS, LOAD_LOGS_FAILURE} from '../constants/index';
export function selectLog(logToSelect){
    return {
        type: SELECT_LOG,
        payload: logToSelect
    };
}
export function loadLogs(){
    return (dispatch) => {
        dispatch({
            type: LOAD_LOGS_PENDING
        });
        //Do load stuff
        dispatch({
            type: LOAD_LOGS_SUCCESS,
            payload: {},//logs
        });
        /*
        dispatch({
            type: LOAD_LOGS_FAILURE
        });
        */
    }
}
export function filterLogs(filters){
    return {
        type: APPLY_FILTER,
        payload: filters,
    };
}