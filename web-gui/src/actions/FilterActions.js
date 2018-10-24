import {CHANGE_START_RANGE, CHANGE_END_RANGE, CHANGE_SENDER_FILTER, CLEAR_FILTER, CHANGE_RECIPIENT_FILTER} from '../constants';

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

export function changeSender(sender){
    return {
        type: CHANGE_SENDER_FILTER,
        payload: sender,
    };
}

export function changeRecipient(recipient){
    return {
        type: CHANGE_RECIPIENT_FILTER,
        payload: recipient,
    };
}

export function clearFilter(){
    return {
        type: CLEAR_FILTER
    };
}