import { INITIALIZE_REQUESTS } from "../constants/index";

const initialState=[];
export default function requests(state = initialState, action) {
    switch (action.type) {
      case INITIALIZE_REQUESTS:
        return action.payload;
      default:
        return state
    }
  }