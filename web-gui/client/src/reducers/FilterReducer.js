import {CHANGE_START_RANGE, CHANGE_END_RANGE, CHANGE_REQUEST_FILTER, CLEAR_FILTER, CHANGE_RESPONSE_FILTER} from '../constants';
const initialState={
    startRange: (new Date(1970,1,1,0,0,0,0)),
    endRange: (new Date()),
    request: "",
    response: "",
}
export default function filter(state = initialState, action) {
    switch (action.type) {
      case CHANGE_START_RANGE:
        return  {...state, startRange:action.payload};
      case CHANGE_END_RANGE:
        return  {...state, endRange:action.payload};
      case CHANGE_REQUEST_FILTER:
        return  {...state, request: action.payload};
      case CHANGE_RESPONSE_FILTER:
        return {...state, response: action.payload};
      case CLEAR_FILTER:
        return {...initialState};
      default:
        return state
    }
  }