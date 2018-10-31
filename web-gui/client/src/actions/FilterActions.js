import {CHANGE_START_RANGE, CHANGE_END_RANGE, CHANGE_REQUEST_FILTER, CLEAR_FILTER, CHANGE_RESPONSE_FILTER} from '../constants';

export function changeStartRange(datetime){
    return {
        type: CHANGE_START_RANGE,
        payload: datetime,
    };
}

export function changeEndRange(datetime){
    return {
        type: CHANGE_END_RANGE,
        payload: datetime,
    };
}

export function changeRequest(sender){
    return {
        type: CHANGE_REQUEST_FILTER,
        payload: sender,
    };
}

export function changeResponse(sender){
    return {
        type: CHANGE_RESPONSE_FILTER,
        payload: sender,
    };
}

export function clearFilter(){
    return {
        type: CLEAR_FILTER
    };
}