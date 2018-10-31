import {INITIAL_STATE, PENDING_STATE,SUCCESS_STATE, FAILURE_STATE, LOAD_LOGS_PENDING, LOAD_LOGS_SUCCESS, LOAD_LOGS_FAILURE} from '../constants';
const initialState={
    loadState: INITIAL_STATE,
}
export default function filter(state = initialState, action) {
    switch (action.type) {
      case LOAD_LOGS_PENDING:
        return {loadState: PENDING_STATE};
      case LOAD_LOGS_SUCCESS:
        return {loadState: SUCCESS_STATE};
      case LOAD_LOGS_FAILURE:
        return {loadState: FAILURE_STATE};
      default:
        return state
    }
  }