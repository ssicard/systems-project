import {CHANGE_START_RANGE, CHANGE_END_RANGE, CHANGE_SENDER_FILTER, CLEAR_FILTER, CHANGE_RECIPIENT_FILTER} from '../constants';
const initialState={
    startRange: (new Date(1970,1,1,0,0,0,0)),
    endRange: (new Date()),
    sender: "",
    recipient: "",
}
export default function filter(state = initialState, action) {
    switch (action.type) {
      case CHANGE_START_RANGE:
        return  {...state, startRange:action.payload};
      case CHANGE_END_RANGE:
        return  {...state, endRange:action.payload};
      case CHANGE_SENDER_FILTER:
        return  {...state, sender: action.payload};
      case CHANGE_RECIPIENT_FILTER:
        return {...state, recipient: action.payload};
      case CLEAR_FILTER:
        return {...initialState};
      default:
        return state
    }
  }