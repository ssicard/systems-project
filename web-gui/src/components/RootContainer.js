import React, { Component } from 'react';
import {connect} from 'react-redux';
import CircularProgress from '@material-ui/core/CircularProgress';
import LogContainer from './LogContainer';
import MessageViewer from './MessageViewer';
import HeaderBar from './HeaderBar';
import {PENDING_STATE, INITIAL_STATE} from '../constants';
import {loadLogs} from '../actions/LogActions';
import Button from '@material-ui/core/Button/Button';
class RootContainer extends Component {
  styles = {
    appBarContainer: {
      flex: 1,
    },
    mainAppContainer: {
      flex: 9,
      flexDirection: 'row',
      display: 'flex',
    },
  }
  renderContent=()=>{
    if(this.props.loadState == PENDING_STATE){
      return (
        <div style={this.styles.mainAppContainer}>
          <CircularProgress />
        </div>
      );
    } else if(this.props.loadState == INITIAL_STATE){
      return(
        <div style={this.styles.mainAppContainer}>
          <Button onClick={this.props.loadLogs}>
            Load Logs
          </Button>
        </div>
      )
    }else {
      return (
        <div style={this.styles.mainAppContainer}>
          <LogContainer />
          <MessageViewer />
        </div>
      );
    }
  }
  render() {
    return (
      <div>
        <div style={this.styles.appBarContainer}>
        <HeaderBar />
        </div>
        <div style={this.styles.mainAppContainer}>
            <LogContainer />
            <MessageViewer />
        </div>
      </div>
    );
  }
}
const mapStateToProps = store =>{
  return ({
    loadState: store.loadState,
  })
}
export default connect(mapStateToProps,{loadLogs})(RootContainer);
