import {SELECT_LOG, APPLY_FILTER, LOAD_LOGS_PENDING, LOAD_LOGS_SUCCESS, LOAD_LOGS_FAILURE, EXPAND_LOG, CREATE_LOGS} from '../constants/index';
export function selectLog(logToSelect){
    return {
        type: SELECT_LOG,
        payload: logToSelect
    };
}
export function expandLog(logToExpand){
    return {
        type: EXPAND_LOG,
        payload: logToExpand,
    };
}
export function loadLogs(){
    return (dispatch) => {
        dispatch({
            type: LOAD_LOGS_PENDING
        });
        //Do load stuff
        console.log('in the load logs function');
        fetch('http://ec2-54-186-191-42.us-west-2.compute.amazonaws.com:5000/api/logs', {
            method: "GET",
        })
        .then(res => {console.log('got response'); console.log(res);return res.json()})
        .then(res=> {
            console.log('response');
            console.log(res);
            let requests = [];
            let responses = [];
            let messages ={};
            for(var i = 0;i<res.length;i++){
                let newObj = {};
                newObj.timestamp = res[i].SentDateTime;
                newObj.sender = res[i].ContactDescription;
                newObj.guid = res[i].MessageID;
                messages[res[i].MessageID] = res[i].MessageDescription;
                if(res[i].RecalledMessageID==null){
                    requests.push(newObj);
                } else {
                    newObj.responseTo = res[i].RecalledMessageID;
                    responses.push(newObj);
                }
            }
            dispatch({
                type: CREATE_LOGS,
                payload: {requests: requests, responses: responses},
            });
            console.log('sending load logs success');
            dispatch({
                type: LOAD_LOGS_SUCCESS,
                payload: {messages: messages}
            });

        })
        .catch(err=> {
            console.log('request error');
            console.log(err);
            dispatch({
                type: LOAD_LOGS_FAILURE
            });
        });
    }
}
export function filterLogs(filters){
    return {
        type: APPLY_FILTER,
        payload: filters,
    };
}
export function createLogs(requests, responses){
    console.log(requests);
    console.log(responses);
    return {
        type: CREATE_LOGS,
        payload: {requests:requests, responses:responses}
    };
}