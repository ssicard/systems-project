import React, {Component} from 'react';
import {connect} from 'react-redux';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Typography from '@material-ui/core/Typography';
import TextField from '@material-ui/core/TextField';
import InputBase from '@material-ui/core/InputBase';
import Button from '@material-ui/core/Button';
import SearchIcon from '@material-ui/icons/Search';
import FilterIcon from '@material-ui/icons/FilterList';
import XIcon from '@material-ui/icons/HighlightOff';
import {changeRequest, changeResponse, changeStartRange, changeEndRange, clearFilter} from '../actions/FilterActions';
import {filterLogs} from '../actions/LogActions';
class HeaderBar extends Component{
    styles = {
      searchBar: {
        display: 'flex',
        flexDirection: 'row',
        justifyContent: 'center',
      },
      timePicker: {
        paddingLeft: '20px',
        color: '#FFFFFF',
      },
      appBar: {
        backgroundColor: '#4286f4',
        color: '#ffffff',
      },
      appTitle: {
        color: '#ffffff',
        letterSpacing: 3,
      },
      searchInput: {
        color:'#FFFFFF',
        paddingLeft:'2px',
      },
      filterButton: {
        backgroundColor:'#0e65f2',
      },
      buttonIcon: {
        paddingLeft:'10px'
      }

    }
  
    render() {
        return (
            <div>
              <AppBar position="static" style={this.styles.appBar}>
                <Toolbar>
                  <Typography variant="title" style={this.styles.appTitle}>
                    Emergency System  Logs
                  </Typography>
                  <div style={this.styles.timePicker}>
                    <TextField
                      id="datetime-local"
                      label="Start of Range"
                      type="datetime-local"
                      InputLabelProps={{
                      shrink: true,
                      }}
                      onChange={(change)=>{this.props.changeStartRange((new Date(change.target.value)));}}
                    />
                  </div>
                  <div style={this.styles.timePicker}>
                    <TextField
                      id="datetime-local"
                      label="End of Range"
                      type="datetime-local"
                      InputLabelProps={{
                      shrink: true,
                      }}
                      onChange={(change)=>{this.props.changeEndRange((new Date(change.target.value)));}}
                    />
                  </div>
                  <div style={this.styles.searchBar}>
                    <div>
                      <SearchIcon />
                    </div>
                    <InputBase
                      placeholder="Search Requests"
                      style={this.styles.searchInput}
                      onChange={(change)=>{this.props.changeRequest(change.target.value);}}
                      value={this.props.filter.sender}
                    />
                  </div>
                  <div style={this.styles.searchBar}>
                    <InputBase
                      placeholder="Search Responses"
                      style={this.styles.searchInput}
                      onChange={(change)=>{this.props.changeResponse(change.target.value);}}
                      value={this.props.filter.recipient}
                    />
                  </div>
                  <Button variant="contained" color="secondary" style={this.styles.filterButton} onClick={()=>{console.log(this.props.filter);this.props.filterLogs(this.props.filter);}}>
                    Filter
                    <FilterIcon  style={this.styles.buttonIcon}/>
                  </Button>
                  <Button variant="contained" color="secondary" onClick={this.props.clearFilter}>
                    Clear
                    <XIcon  style={this.styles.buttonIcon}/>
                  </Button>
                </Toolbar>
              </AppBar>
            </div>
          );
    }
}
const mapStateToProps = store =>{
  return ({
    filter:store.filter,
  })
}
export default connect(mapStateToProps,{changeRequest, changeResponse, changeStartRange, changeEndRange, clearFilter, filterLogs})(HeaderBar);