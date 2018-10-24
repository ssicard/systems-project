import React, { Component } from 'react';
import Paper from '@material-ui/core/Paper';
import ArrowIcon from '@material-ui/icons/ArrowRightAlt'
import { connect } from 'react-redux';
import {selectLog} from '../actions/LogActions';

class LogEntry extends Component {
    styles = {
        entryInnerContainer: {
            display: "flex",
            padding:"5px",
            flexDirection:"row",
            flex:1,
        },
        entryDataLeftCell: {
            flex:2,
            paddingLeft: "10px",
            paddingRight: "10px",
            borderRight: "2px solid black",
            borderColor: "#85aef2",
            borderRadius: "2px",
            alignItems: "center",
            flexDirection: 'column',

        },
        entryDataMiddleCell: {
            paddingLeft: "10px",
            paddingRight: "10px",
            alignItems: "center",
            flexDirection: 'column',
        },
        entryDataRightCell: {
            paddingLeft: "10px",
            paddingRight: "10px",
            alignItems: "center",
            flexDirection: 'column',
        },
        label: {
            paddingBottom:'2px',
            color: '#AAAAAA',
            fontSize: '13px',
        },
        sourceDestContainer:{
            flex:2,
            display: 'flex',
            flexDirection: 'row',
            alignItems: 'center',
            justifyContent: 'center',
        }
    }
  getEntryContainerStyle = () =>{
      if(this.props.selectedLog==this.props.guid){
          return {marginBottom:'5px', border: '2px solid red'};
      } else {
          return {marginBottom: '5px'};
      }
  }
  getLeftCellStyle = () => {
    if(this.props.selectedLog == this.props.guid){
        return {...this.styles.entryDataLeftCell, borderColor:'red'};
    } else {
        return this.styles.entryDataLeftCell;
    }
  }
  getArrowIconStyle =()=>{
      if(this.props.selectedLog == this.props.guid){
          return {color: 'red'}
      } else {
          return {color: '#85aef2'}
      }
  }
  selectLog = () => {
    if(this.props.selectedLog==this.props.guid){
        this.props.selectLog(-1);
    } else {
        this.props.selectLog(this.props.guid);
    }
  }
  render() {
    return (
      <Paper
       style={this.getEntryContainerStyle()}
       onClick={this.selectLog}
      >
        <div name="entryInnerContainer" style={this.styles.entryInnerContainer}>
          <div name="time" style={this.getLeftCellStyle()}>
                <div style={this.styles.label}>
                    Time
                </div>
                <div>
                    {this.props.time}
                </div>
          </div>
          <div name="sourceDestContainer" style={this.styles.sourceDestContainer}>
            <div name="sender" style={this.styles.entryDataMiddleCell}>
                    <div style={this.styles.label}>
                        Sender
                    </div>
                    <div>
                        {this.props.sender}
                    </div>
            </div>
            <ArrowIcon style={this.getArrowIconStyle()}/>
            <div name="recipient" style={this.styles.entryDataRightCell}>
                    <div style={this.styles.label}>
                        Recipient
                    </div>
                    <div>
                        {this.props.recipient}
                    </div>
            </div>
          </div>
        </div>
      </Paper>
    );
  }
}
const mapStateToProps = store =>{
    return {
        selectedLog: store.selectedLog.selectedLog
    };
}
export default connect(mapStateToProps, {selectLog})(LogEntry);
